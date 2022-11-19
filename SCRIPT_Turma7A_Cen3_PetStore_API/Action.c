Action()
{
	
	lr_save_datetime("%Y-%m-%d", DATE_NOW, "pDateNow");
	lr_save_datetime("%H:%M:%S", TIME_NOW, "pTimeNow");
	lr_save_datetime("%Y-%m-%dT%H:%M:%S", DATE_NOW, "pDateTimeNow");

//	lr_save_datetime("%Y-%m-%d", DATE_NOW+(ONE_DAY*(365)), "pDateFinal");
//	lr_save_datetime("%H:%M:%S", TIME_NOW-(ONE_MIN*(10)), "pTimeFinal");

	lr_think_time(1);
	
	lr_start_transaction("01_RealizarPedido");
	
	web_reg_save_param("id",
		"LB=id\":",
		"RB=,\"petId",
		"Search=Body",
		LAST);
	
	web_reg_save_param_json(
		"ParamName=idJSON",
		"QueryString=$.id",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_custom_request("realizarPedido",
		"URL=https://petstore.swagger.io/v2/store/order",
		"Method=POST",
		"Snapshot=t1.inf",
		"EncType=application/json",
		"Body="
		"{"
		"\"id\": {p_id},"
		"\"petId\": {p_petId},"
		"\"quantity\": {p_quant},"
		"\"shipDate\": \"{pDateTimeNow}.429Z\","
		"\"status\": \"placed\","
		"\"complete\": true"
		"}",
		LAST);
	
	lr_end_transaction("01_RealizarPedido", LR_AUTO);

	lr_think_time(1);

	lr_start_transaction("02_ConsultarPedido");
	
	web_custom_request("consultarPedido",
		"URL=https://petstore.swagger.io/v2/store/order/{id}",
		"Method=GET",
		"Snapshot=t2.inf",
		"EncType=application/json",
		LAST);	
	
	lr_end_transaction("02_ConsultarPedido", LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("03_ExcluirPedido");
	
	web_custom_request("excluirPedido",
		"URL=https://petstore.swagger.io/v2/store/order/{id}",
		"Method=DELETE",
		"Snapshot=t3.inf",
		"EncType=application/json",
		LAST);	
	
	lr_end_transaction("03_ExcluirPedido", LR_AUTO);	
	
	return 0;
}
