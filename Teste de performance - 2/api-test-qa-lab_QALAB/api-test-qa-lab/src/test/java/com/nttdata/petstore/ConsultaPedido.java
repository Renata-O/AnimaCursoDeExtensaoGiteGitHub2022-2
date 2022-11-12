package com.nttdata.petstore;

import net.serenitybdd.rest.SerenityRest;
import net.thucydides.core.annotations.Step;

import static net.serenitybdd.rest.SerenityRest.*;

public class ConsultaPedido {

    private static String CONSULTA_PEDIDO = "https://petstore.swagger.io/v2/user";

    @Step("Consultar pedido {0} en PetStore")
    public void consultarPedido(String pedido1, String pedido2){
        given()
                .contentType("application/json")
                .body("{\n" +
                        "  \"id\": 0,\n" +
                        "  \"username\": \""+pedido1+"\",\n" +
                        "  \"firstName\": \""+pedido2+"\",\n" +
                        "}")
                .GET(CONSULTA_PEDIDO);

    }
}
