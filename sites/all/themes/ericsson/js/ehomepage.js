			var eUserFlashversion = YAHOO.util.SWFDetect.getFlashVersion();
			// Show Globe
			if(eUserFlashversion >= 9.115 ){
				var params = {
					version: 9.115,
					useExpressInstall: true,
					flashVars: {
						main: "/shared/eipa/swf/homepage/Ericsson_globe.swf",
						path: "/shared/eipa/swf/homepage/assets",
						feed: "home/atom.xml",
						copypath: "/shared/eipa/swf/homepage/assets/xml/copy_se.xml",
						market: "se",
						v: "11"
					},
					fixedAttributes: {
						menu: false,
						quality: "high",
						allowFullScreen: true,
						allowScriptAccess: "sameDomain",
						wmode: "transparent"
					}
				};
				if (YUD.get("eHomePageBigFlash")) {
					var newswf = new YAHOO.widget.SWF("eHomePageBigFlash", "/shared/eipa/swf/homepage/assets/swf/preloader.swf", params);
				}
			// Show text view
			}else{
					YUD.setStyle('eFlashFallback1','display','block');
					YUD.setStyle('eFlashFallback2','display','block');
					YUD.removeClass('eFlashShow','eToolBarLinkActive');
					YUD.addClass('eTextShow','eToolBarLinkActive');
					YUD.removeClass('eFlashShowTab','eShow');
					YUD.addClass('eTextShowTab','eShow');
					YUD.setStyle('eToolbarGroupContainer','background','#FFF');
					sIFR.replace(eSifrEricssonMaster, {selector: 'h2.eH2Sifr, h3.eH3Sifr'});
			}					