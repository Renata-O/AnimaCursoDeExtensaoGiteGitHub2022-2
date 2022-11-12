package com.nttdata.petstore;

import io.cucumber.java.en.And;
import io.cucumber.java.en.Then;
import io.cucumber.java.en.When;
import net.serenitybdd.rest.SerenityRest;
import net.thucydides.core.annotations.Steps;

import static net.serenitybdd.rest.SerenityRest.restAssuredThat;
import static org.hamcrest.CoreMatchers.equalTo;

public class CrearPedidoStepsDefs {

    @Steps
    CrearPedido crearPedido;

    @When("creo el pedido con pedido1 {string}, pedido2 {string}")
    public void setCrearPedido(String pedido1, String Pedido2){
        crearPedido.crearPedido(pedido1, pedido1);
    }

    @Then("el código de respuesta es {int}")
    public void elCódigoDeRespuestaEs(int statusCode) {
        restAssuredThat(response -> response.statusCode(statusCode));
    }

    @And("el type es {string}")
    public void elTypeEs(String type) {
        restAssuredThat(response -> response.body("'type'", equalTo(type)));
        System.out.println("Type: " + SerenityRest.lastResponse().body().path("type").toString());
        System.out.println(SerenityRest.lastResponse().print());
    }
}
