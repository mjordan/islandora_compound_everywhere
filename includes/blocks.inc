<?php

/**
 * @file
 * Holds block definitions for the Islandora Compound Everywhere module.
 */

/**
 * Constructs the navigation block for a compound.
 *
 * @param AbstractObject $object
 *   If supplied the object to create the block for.
 *
 * @return array
 *   Renderable array for the block.
 */
function islandora_compound_everywhere_navigation_block(AbstractObject $object = NULL) {
  module_load_include('inc', 'islandora', 'includes/utilities');
  drupal_add_css(drupal_get_path('module', 'islandora_compound_object') . '/css/islandora_compound_object.block.css');
  if ($object) {
    $output = '';
    if ($object) {
      $compound_info = islandora_compound_object_retrieve_compound_info($object, TRUE);
      // This object is part of a compound object.
      if (!empty($compound_info)) {
        $prev_next = theme('islandora_compound_prev_next', $compound_info);
        $output .= $prev_next;
      }

      if (!empty($output)) {
        return array('#markup' => $output);
      }
    }
  }
}
