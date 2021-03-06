<?php

/**
 * Simple custom text box.
 */
class twitter_pull_box extends boxes_box {
  /**
   * Implementation of boxes_box::options_defaults().
   */
  public function options_defaults() {
   return array(
     'title'=>'',
     'search' => '',
     'max_results' => 20,
     'additional_classes' => '',
   );
  }

  /**
   * Implementation of boxes_box::options_form().
   */
  public function options_form(&$form_state) {
    $form = array();
      
    $form['search'] = array(
      '#type' => 'textfield',
      '#title' => t('Twitter Search'),
      '#required' => TRUE,
      '#default_value' => $this->options['search'],
      '#description' => t('The twitter user or hashtag to build this box off of.'),
    );
    $form['max_results'] = array(
      '#type' => 'textfield',
      '#title' => t('Max Tweets'),
      '#default_value' => $this->options['max_results'],
      '#description' => t('How many tweets you want the box to display at any one time.'),
    );
    return $form;
  }

  /**
   * Implementation of boxes_box::render().
   */
  public function render() {
    $content = twitter_pull_render($this->options['search'], NULL, $this->options['max_results']);
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    return array(
      'delta' => $this->delta, // Crucial.
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }
}
