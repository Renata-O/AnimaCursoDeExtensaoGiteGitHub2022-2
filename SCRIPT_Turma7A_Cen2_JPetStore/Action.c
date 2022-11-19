Action()
{

	web_cache_cleanup();
	
	lr_think_time(3);
	
	lr_start_transaction("02_Busca_A");
	
	web_submit_data("Catalog.action", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value={valorA}", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value={sourcePage}", ENDITEM, 
		"Name=__fp", "Value={fp}", ENDITEM, 
		LAST);	

	lr_end_transaction("02_Busca_A",LR_AUTO);

	lr_think_time(3);
	
	lr_start_transaction("03_Busca_B");
	
	web_submit_data("Catalog.action", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value={valorB}", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value={sourcePage}", ENDITEM, 
		"Name=__fp", "Value={fp}", ENDITEM, 
		LAST);	

	lr_end_transaction("03_Busca_B",LR_AUTO);	
	
	return 0;
}