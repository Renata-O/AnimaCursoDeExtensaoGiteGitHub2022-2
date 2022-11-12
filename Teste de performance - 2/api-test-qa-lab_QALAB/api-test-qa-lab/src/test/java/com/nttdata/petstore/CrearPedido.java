package com.nttdata.petstore;

import net.serenitybdd.rest.SerenityRest;
import net.thucydides.core.annotations.Step;

public class CrearPedido {

    private static String CREATE_PEDIDO = "https://petstore.swagger.io/v2/user";

    @Step("Crear pedido {0} en PetStore")
    public void crearPedido(String pedido1, String pedido2){
        SerenityRest.given()
                .contentType("application/json")
                .body("{\n" +
                        "  \"id\": 0,\n" +
                        "  \"username\": \""+pedido1+"\",\n" +
                        "  \"firstName\": \""+pedido2+"\",\n" +
                        "}")
                .post(CREATE_PEDIDO);

    }
}
