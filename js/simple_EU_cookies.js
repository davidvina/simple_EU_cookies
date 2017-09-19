(function ($) {

  Backdrop.behaviors.simple_EU_cookies = {
    attach: function (context, settings) {





    // get languages browser
    var lang = $('html').attr('lang');

		var message = settings.simple_EU_cookies[lang+"_message"];

		var accept_text = settings.simple_EU_cookies[lang+"_accept_text"];

		var expire_days = settings.simple_EU_cookies.expire_days;


		var privacy_police_button = settings.simple_EU_cookies.privacy_police_button;
		if(privacy_police_button == 0){
			privacy_police_button = false;
		} else {
			privacy_police_button = true;
		}

		var privacy_police_url = settings.simple_EU_cookies.privacy_police_url;
		var privacy_police_text = settings.simple_EU_cookies.privacy_police_text;

		var position_fixed = settings.simple_EU_cookies.position_fixed;
		if(position_fixed == 0){
			position_fixed = false;
		} else {
			position_fixed = true;
		}


    	$.cookieBar({
  			message: message,
  			acceptText: accept_text,
  			//declineButton: decline_function,
  			//declineText: decline_text,
  			expireDays: expire_days,
  			policyButton: privacy_police_button,
  			policyText: privacy_police_text,
  			policyURL: privacy_police_url,
  			fixed: position_fixed,
  			bottom: true,
  			zindex: '10000',
  			forceShow: false,
        // acceptOnContinue: true,
        // acceptOnScroll: true,
        // acceptAnyClick: true,
		});

    }
  };

})(jQuery);
