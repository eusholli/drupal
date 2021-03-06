<?php //$Id: views_handler_field_geo.inc,v 1.4 2009/06/04 02:02:19 vauxia Exp $

class views_handler_field_geo extends views_handler_field {
  function options_form(&$form, &$form_state) {
    // TODO Implement settings for AsKML, AsSVG, AsText, etc.
    // By the way, those would only apply to postgis for now.
    $form['geo_format'] = array(
      '#type' => 'select',
      '#options' => geo('query_functions', ($this->definition['geo_type'])),
      '#default_value' => $this->options['geo_format'],
    );
  }

  function query() {
    $format = $this->options['geo_format'];
    if (!$format) $format = 'wkt';

    // Add the geo formula as a field.
    if ($format) {
      $func = geo('query_'. $format, $this->real_field, array('aggregate' => TRUE));
    }
    else {
      $func = geo('query_'. $format, $this->real_field, array('aggregate' => TRUE));
    }
    $table = $this->ensure_my_table();
    $this->query->add_field(NULL, $func, $table, array('aggregate' => TRUE));
  }
}
