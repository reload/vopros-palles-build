<?php

/**
 * @file
 * Drush commands/hooks for Palles Gavebod Vopros.
 */

/**
 * Implements hook_drush_sql_sync_sanitize().
 */
function palles_vopros_drush_sql_sync_sanitize($site) {
  // Update the opensearch URL in the variables table.
  // $sanitize_query = "UPDATE variable SET value='" . serialize("http://opensearchadmin.addi.dk/next_2.0/") . "' WHERE name = 'osa_addi_soap_url';";
  // drush_sql_register_post_sync_op('opensearch_url', dt('Set opensearch URL'), $sanitize_query);

  // Fix mailhandler mailbox email so it wont get mail destined for production.
  $boxes = drush_db_select('mailhandler_mailbox', array('mid', 'settings', 'admin_title'));

  $i = 1;
  while ($box = drush_db_fetch_object($boxes)) {
    $settings = unserialize($box->settings);
    if ($settings['mail'] == 'spv@pallesgavebod.dk') {
      // Replace the main address with test@.
      $mail = 'test@pallesgavebod.dk';
    }
    else {
    // Replace the rest with test+<num>@.
      $mail = 'test+' . $i++ . '@pallesgavebod.dk';
    }
    $settings['name'] = $mail;
    $sanitize_query = "UPDATE mailhandler_mailbox SET mail = '" . $mail . "', admin_title = '" . $mail . "', settings = '" . serialize($settings) . "' WHERE mid = " . $box->mid . ";";
    drush_sql_register_post_sync_op('mailbox_' . $mail, dt('Fix mailbox @box', array('@box' => $box->admin_title)), $sanitize_query);

  }

  // Fix Solr server port number.
  $servers = drush_db_select('search_api_server', array('id', 'options', 'name'));
  while ($server = drush_db_fetch_object($servers)) {
    $options = unserialize($server->options);
    // Use this to change port number:
    // $options['port'] = '8983';
    // $sanitize_query = "UPDATE search_api_server SET options = '"
    // . serialize($options) . "' WHERE id = " . $server->id . ";";

    // We don't want to mess with the production Solr data, so disable the server.
    $sanitize_query = "UPDATE search_api_server SET enabled = 0 WHERE id = " . $server->id . ";";
    drush_sql_register_post_sync_op('search_api_' . $server->id, dt('Fix search_api server @server', array('@server' => $server->name)), $sanitize_query);

  }
}
