<?php

/**
 *  configuration admin module
 */

function simple_EU_cookies_admin_form(){
  $form = array();

  	// accedemos al archivo de configuracion donde guardamos los datos de configuracion
  	$config = config('simple_EU_cookies.settings');


	$form['message'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Message cookie law'),
		'#description' => t('Enter the text to show on the cookie law bar.'),
		'#default_value' => $config->get('message'),
		'#required' => TRUE,
	);

	$form['accept_text'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Accept Text'),
		//'#description' => t('Enter the text to show on the cookie law bar.'),
		'#default_value' => $config->get('accept_text'),
		'#required' => TRUE,
	);

	$form['privacy_police_button'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Privace police button'),
		'#description' => t('Show decline link to privacy police or not.'),
		'#default_value' => $config->get('privacy_police_button'),
		//'#required' => TRUE,
	);

	$form['privacy_police_url'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Privacy policy link'),
		'#description' => t('Enter link to your privacy policy or other page that will explain cookies to your users. Use absolute URL.'),
		'#default_value' => $config->get('privacy_police_url'),
		//'#required' => TRUE,
		'#states' => array(
			'visible' => array(
				':input[name="privacy_police_button"]' => array('checked' => TRUE),
			),
		),
	);

	$form['privacy_police_text'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Privacy policy link text'),
		'#description' => t('Enter text for the link to your privacy policy. Use absolute URL.'),
		'#default_value' => $config->get('privacy_police_text'),
		//'#required' => TRUE,
		'#states' => array(
			'visible' => array(
				':input[name="privacy_police_button"]' => array('checked' => TRUE),
			),
		),
	);

	$form['expire_days'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Expire days'),
		'#description' => t('Number of days to save the cookie law.'),
		'#default_value' => $config->get('expire_days'),
		'#required' => TRUE,
		'#maxlength' => 3,
		'#size' => 4,
		'#element_validate' => array('element_validate_number'),
	);
	/*
	$form['decline_function'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Use decline function'),
		'#description' => t('Show decline text or not.'),
		'#default_value' => $config->get('decline_function'),
		//'#required' => TRUE,
	);

	$form['decline_text'] = array(
		'#type' => 'textfield',
		'#title' =>  t('Decline Text'),
		//'#description' => t('Enter the text to show on the cookie law bar.'),
		'#default_value' => $config->get('decline_text'),
		//'#required' => TRUE,
		'#states' => array(
			'visible' => array(
				':input[name="decline_function"]' => array('checked' => TRUE),
			),
		),
	);
	*/
	$form['position_fixed'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Position fixed'),
		'#description' => t('Add css class .fixed to cookie-bar'),
		'#default_value' => $config->get('position_fixed'),
		//'#required' => TRUE,
	);

	$form['custom_css'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Custom css'),
		'#description' => t('Use custom css (true) or module css (false). If you check this copy the css from jquery.cookiebar.css to your theme'),
		'#default_value' => $config->get('custom_css'),
		//'#required' => TRUE,
	);

	$form['actions']['#type'] = 'actions';

	// este boton tiene que estar activado si se puede conectar con base de datos
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save config'),
	);



  	return $form;
}


/*
*  Validation function for number
*/

function element_validate_number($element, &$form_state, $form) {

	// comprobamos que se a un numero
	if(!ctype_digit($element['#value'])){
		form_error($element, t('The value must be a integer number.'));
	}

}


/*
*	Validate form
*/

function simple_EU_cookies_admin_form_validate($form, $form_state){

	if($form_state['values']['privacy_police_button'] == 1){
		if($form_state['values']['privacy_police_url'] == ''){
			form_set_error('privacy_police_url', t('If you choose privacy police button, you need url.'));
		}

		if($form_state['values']['privacy_police_text'] == ''){
			form_set_error('privacy_police_text', t('You need a text for your button.'));
		}
	}

}


/*
*
*/

function simple_EU_cookies_admin_form_submit($form, $form_state){
	//hdcvi_products_importar_info();
	$config = config('simple_EU_cookies.settings');

	$config->set('message', $form_state['values']['message']);
	$config->set('accept_text', $form_state['values']['accept_text']);


	$config->set('privacy_police_button', $form_state['values']['privacy_police_button']);
	$config->set('privacy_police_url', $form_state['values']['privacy_police_url']);
	$config->set('privacy_police_text', $form_state['values']['privacy_police_text']);

	
	$config->set('expire_days', $form_state['values']['expire_days']);
	//$config->set('decline_function', $form_state['values']['decline_function']);
	//$config->set('decline_text', $form_state['values']['decline_text']);
	$config->set('position_fixed', $form_state['values']['position_fixed']);
	$config->set('custom_css', $form_state['values']['custom_css']);

	// save on simple_EU_cookies.settings
	$config->save();

}




