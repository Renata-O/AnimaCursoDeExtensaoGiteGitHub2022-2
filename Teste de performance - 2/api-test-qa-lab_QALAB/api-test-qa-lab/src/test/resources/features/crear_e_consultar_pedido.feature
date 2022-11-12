Feature: Crear pedido PetStore

  @test1
  Scenario: Crear pedido

    When creo el pedido con pedido1 {string}, pedido2 {string}
    Then el código de respuesta es 200
    And el type es "unknown"