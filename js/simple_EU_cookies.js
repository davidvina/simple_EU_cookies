(function ($) {

  Backdrop.behaviors.simple_EU_cookies = {
    attach: function (context, settings) {

    	  //  cogemos datos de config file
		  //  "privacy_police_url": "aviso-legal",
		  //  "message": "We use cookies to track usage and preferences",
		  //  "accept_text": "I Understand",
		  //  "expire_days": "90",
		  //  "decline_function": 0,
		  //  "decline_text": "Disable Cookies",
		  //  "position_fixed": 1,
		  //  "custom_css": 1

		var message = settings.simple_EU_cookies.message;

		var accept_text = settings.simple_EU_cookies.accept_text;

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
			fixed: true,
			bottom: true,
			zindex: '10000',
			forceShow: true,
		});

    }
  };

})(jQuery);