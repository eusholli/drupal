<?php

function template_preprocess_gmap_geo_view_gmap(&$vars) {
  // rows is our map array
  $vars['map_array'] = $vars['rows'];
  unset($vars['rows']);

  // theme the map
  $vars['map'] = theme('gmap', $vars['map_array']);
}
