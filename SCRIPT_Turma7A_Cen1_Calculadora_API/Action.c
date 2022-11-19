Action()
{

	lr_think_time(1);
	
	lr_start_transaction("01_Adicao");

	web_reg_save_param("ResultadoAdicao",
		"LB=<AddResult>",
		"RB=</AddResult>",
		"Search=Body",
		LAST);
	
	web_reg_save_param_xpath(
		"ParamName=ResultadoXpath",
		"QueryString=//AddResult",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);

	
	web_custom_request("add",
		"URL=http://www.dneonline.com/calculator.asmx?wsdl",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t1.inf",
		"EncType=text/xml;charset=UTF-8",
		"Body=<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:tem=\"http://tempuri.org/\">   <soapenv:Header/>   <soapenv:Body>      <tem:Add>         <tem:intA>{intA}</tem:intA>         <tem:intB>{intB}</tem:intB>      </tem:Add>   </soapenv:Body></soapenv:Envelope>",
		LAST);	
	
	lr_end_transaction("01_Adicao", LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("02_Divisao");
	
	web_reg_save_param("ResultadoDivisao",
		"LB=<DivideResult>",
		"RB=</DivideResult>",
		"Search=Body",
		LAST);
	
	web_custom_request("divide",
		"URL=http://www.dneonline.com/calculator.asmx?wsdl",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t2.inf",
		"EncType=text/xml;charset=UTF-8",
		"Body=<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:tem=\"http://tempuri.org/\">   <soapenv:Header/>   <soapenv:Body>      <tem:Divide>         <tem:intA>{intA}</tem:intA>         <tem:intB>{intB}</tem:intB>      </tem:Divide>   </soapenv:Body></soapenv:Envelope>",
		LAST);

	lr_end_transaction("02_Divisao", LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("03_Multiplicacao");

	web_reg_save_param("ResultadoMultiplicacao",
		"LB=<MultiplyResult>",
		"RB=</MultiplyResult>",
		"Search=Body",
		LAST);
	
	web_custom_request("multiply",
		"URL=http://www.dneonline.com/calculator.asmx?wsdl",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t3.inf",
		"EncType=text/xml;charset=UTF-8",
		"Body=<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:tem=\"http://tempuri.org/\">   <soapenv:Header/>   <soapenv:Body>      <tem:Multiply>         <tem:intA>{intA}</tem:intA>         <tem:intB>{intB}</tem:intB>      </tem:Multiply>   </soapenv:Body></soapenv:Envelope>",
		LAST);

	lr_end_transaction("03_Multiplicacao", LR_AUTO);

	lr_think_time(1);
	
	lr_start_transaction("04_Subtracao");

	web_reg_save_param("ResultadoSubtracao",
		"LB=<SubtractResult>",
		"RB=</SubtractResult>",
		"Search=Body",
		LAST);
	
	web_custom_request("subtract",
		"URL=http://www.dneonline.com/calculator.asmx?wsdl",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t4.inf",
		"EncType=text/xml;charset=UTF-8",
		"Body=<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:tem=\"http://tempuri.org/\">   <soapenv:Header/>   <soapenv:Body>      <tem:Subtract>         <tem:intA>{intA}</tem:intA>         <tem:intB>{intB}</tem:intB>      </tem:Subtract>   </soapenv:Body></soapenv:Envelope>",
		LAST);

	lr_end_transaction("04_Subtracao", LR_AUTO);
	
	lr_output_message("O valor da adição é: %s", lr_eval_string("{ResultadoAdicao}"));
	lr_output_message("O valor da divisão é: %s", lr_eval_string("{ResultadoDivisao}"));
	lr_output_message("O valor da multiplicação é: %s", lr_eval_string("{ResultadoMultiplicacao}"));
	lr_output_message("O valor da subtração é: %s", lr_eval_string("{ResultadoSubtracao}"));
	
	fprintf(fp, "%s,%s,%s,%s\r", lr_eval_string("{ResultadoAdicao}"), lr_eval_string("{ResultadoDivisao}"), lr_eval_string("{ResultadoMultiplicacao}"), lr_eval_string("{ResultadoSubtracao}"));
	
	return 0;
}


