vuser_init()
{
	
	// Criar arquivo texto
	fp = fopen("c:\\temp\\Turma7A.txt", "wb");
	
	// Cabe�alho do arq texto
	fprintf(fp, "%s,%s,%s,%s\r", "adicao", "divisao", "multiplicacao", "subtracao");
	
	return 0;
}
