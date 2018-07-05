<?php

/**
 * @file
 * Admin form functions for Islandora Compound Everywhere.
 */

/**
 * Admin form builder.
 */
function islandora_compound_everywhere_admin_form($form, $form_settings) {
  module_load_include('inc', 'islandora', 'includes/utilities');

  $all_cmodels = islandora_get_content_models();
  $already_chosen = variable_get('islandora_compound_everywhere_selected_cmodels', array());
  $selected_rows = drupal_map_assoc($already_chosen);

  $form['content_model_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure which content models that can display the Compound Everywhere block.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['content_model_wrapper']['compound_everywhere_block_table'] = array(
    '#type' => 'tableselect',
    '#title' => t('Enable the Compound Everywhere block for these content models'),
    '#tree' => TRUE,
    '#multiple' => TRUE,
    '#header' => array(
      'label' => array('data' => t('Content-Model')),
    ),
    '#default_value' => $selected_rows,
  );

  $options = array();
  foreach ($all_cmodels as $cmodel) {
    $pid = $cmodel['pid'];
    $label = $cmodel['label'];
    $options[$pid] = array('label' => array('data' => $label));
  }
  $form['content_model_wrapper']['compound_everywhere_block_table']['#options'] = $options;

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
    '#weight' => 0,
  );

  $form['islandora_compound_everywhere_remove_child_collection_membership'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove child collection membership'),
    '#default_value' => variable_get('islandora_compound_everywhere_remove_child_collection_membership', 0),
    '#description' => t("Check this option if you want to automatically remove child objects' collection membership when they are added to their parents."),
  );

  return $form;
}

/**
 * Submit handler for admin form.
 */
function islandora_compound_everywhere_admin_form_submit(array $form, array &$form_state) {
  $enabled = array_keys(array_filter($form_state['values']['compound_everywhere_block_table']));
  variable_set('islandora_compound_everywhere_selected_cmodels', $enabled);
  variable_set('islandora_compound_everywhere_remove_child_collection_membership', $form_state['values']['islandora_compound_everywhere_remove_child_collection_membership']);
  drupal_set_message(t("Configuration saved."));
}
