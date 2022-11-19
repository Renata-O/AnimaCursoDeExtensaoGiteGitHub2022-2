vuser_init()
{
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_cleanup_cookies();
	
	lr_start_transaction("01_Home");
	
//	sourcePage=CC_veRP5x6gvoaYtFcahOFHy3umwoP1zGCDvqUNlknOUlsrMPyG5mQ-tVBD5iRLnu4QHRDePH4mWEKbDiZwhnyXhI6JWrg2V
	
	web_reg_save_param("sourcePage",
		"LB=_sourcePage\" value=\"",
		"RB=\" /><input type",
		"Search=Body",
		LAST);

// fp=F5k5zgfok8o3hLwG3-bb9DnZ4_3Rq-PUNhUESWRO3YfEivqoeVX0SK2Wx95gNr8o		

	web_reg_save_param("fp",
		"LB=__fp\" value=\"",
		"RB=\" /></div",
		"Search=Body",
		LAST);
	
	web_url("Catalog.action_2", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("01_Home",LR_AUTO);
	
	return 0;
}
