<?php // $Id: views_handler_sort_geo_distance.inc,v 1.1 2009/05/30 04:21:15 vauxia Exp $

class views_handler_sort_geo_distance extends views_handler_sort {
  function pre_query() {
    if (!isset($this->view->field[$this->field]) &&
      !isset($this->view->filter[$this->field])) {

      // Without a target, there's nothing valid to sort on.
      unset($this->view->sort[$this->field]);
    }
  }
}
