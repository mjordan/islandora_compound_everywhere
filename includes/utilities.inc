<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Determine if the object has a content model we want to show the block on.
 *
 * @param \AbstractObject $object
 *   The object we are viewing.
 *
 * @return bool
 *   Whether $object has a content model to show the block for.
 */
function islandora_compound_everywhere_show_for_cmodel(AbstractObject $object) {
  $show_cmodels = variable_get('islandora_compound_everywhere_selected_cmodels', array());
  return (count(array_intersect($object->models, $show_cmodels)) > 0);
}
