<?php

/**
 * @file
 * GMap for Geo style plugin.
 */

/**
 * Style plugin to render a map.
 *
 * @ingroup views_style_plugins
 */
class gmap_geo_plugin_style_gmap extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['macro'] = array('default' => '[gmap ]');
    $options['geo_fields'] = array();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    // this gives us the "grouping" field option
    parent::options_form($form, $form_state);

    $form['macro'] = array(
      '#type' => 'textfield',
      '#title' => t('Macro'),
      '#size' => 1000,
      '#default_value' => $this->options['macro'],
    );

    // build a fieldset of display options for each geo field
    $fields = $this->display->handler->get_handlers('field');
    foreach ($fields as $handler) {
      if (! isset($handler->content_field['geo_type'])) { continue; }
      $field_id = $handler->table . '_' . $handler->real_field;
      $field_options = $this->options['geo_fields'][$field_id];

      $field_config['#type'] = 'fieldset';
      $field_config['#tree'] = TRUE;

      $field_config['#title'] = $handler->ui_name(FALSE);
      $field_config['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Map this field',
        '#default_value' => $field_options['enabled'],
      );

      $field_config['foo'] = array('#value' => 'other config options go here...');

      // these options are commented out because gmap_geo doesn't yet support custom marker/poly/line styles
/*      if ($handler->content_field['geo_type'] == 'point') {
        // choose marker
        $field_config['marker'] = array(
          '#type' => 'gmap_markerchooser',
          '#title' => t('Marker'),
          '#default_value' => $field_options['marker'],
        );
      }
      elseif ($handler->content_field['geo_type'] == 'polyline' || $handler->content_field['geo_type'] == 'polygon') {
        // choose line style
        $field_config['line_color'] = array(
          '#type' => 'textfield',
          '#title' => 'Line color',
          '#size' => 10,
          '#default_value' => $field_options['line_color'],
        );
        $field_config['line_width'] = array(
          '#type' => 'textfield',
          '#title' => 'Line width',
          '#size' => 10,
          '#default_value' => $field_options['line_width'],
        );
        $field_config['line_opacity'] = array(
          '#type' => 'textfield',
          '#title' => 'Line opacity',
          '#size' => 10,
          '#default_value' => $field_options['line_opacity'],
        );
        if ($handler->content_field['geo_type'] == 'polygon') {
          // chose fill style
          $field_config['fill_color'] = array(
            '#type' => 'textfield',
            '#title' => 'Fill color',
            '#size' => 10,
            '#default_value' => $field_options['fill_color'],
          );
          $field_config['fill_opacity'] = array(
            '#type' => 'textfield',
            '#title' => 'Fill opacity',
            '#size' => 10,
            '#default_value' => $field_options['fill_opacity'],
          );
        }
      } */

      $form['geo_fields'][$field_id] = $field_config;
    }
  }

  /**
   * Render the given style.
   */
  function render($values) {
    if (empty($this->row_plugin)) {
      vpr('gmap_plugin_style_gmap: Missing row plugin');
      return;
    }

    $base_map = gmap_parse_macro($this->options['macro']);
    $output = '';

    // this SHOULD to be set in the options_form()...
    foreach ($this->view->field as $field_name => $field) {
      if ($field->content_field['type'] == 'geo') {
        $this->options['geo_fields'][$field_name] = array('enabled' => TRUE, 'field_alias' => $field->field_alias);
      }
    }

    // Group the rows according to the grouping field, if specified.
    $groups = $this->render_grouping($values, $this->options['grouping']);

    foreach ($groups as $title => $rows) {
      // build the map array with view results for each grouping
      $map = $base_map;
      foreach ($this->options['geo_fields'] as $field => $display_options) {
        if (! $display_options['enabled']) { continue; }
        foreach ($rows as $r) {
          $geo_array = geo_wkb_get_data($r->{$display_options['field_alias']}['wkb'], 'array_for_gmap');
          gmap_geo_map_feature($geo_array['value'], $geo_array['type'], $map);
        }
      }
      $output .= theme($this->theme_functions(), $this->view, $this->options, $map, $title);
    }

    // GMap views don't work with Views' live preview since they require js stuff
    if (isset($this->view->live_preview) && $this->view->live_preview) {
      return t('GMap views are not compatible with live preview.');
    }

    return $output;
  }
}
