vuser_init()
{
	web_set_sockets_option ("SSL_VERSION","AUTO");
	
	lr_continue_on_error(LR_ON_ERROR_SKIP_TO_NEXT_ITERATION);

	return 0;
}