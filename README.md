# PI3
Repositorio designado a disciplina de projeto Integrador 3, o projeto em questão é um Detect and Avoid para um drone de peueno porte.
<br><b>Objetivo:</b> Um sistema que detecta e evita para uma aeronave remotamente tripulada.
<br><b>Introdução:</b> em uma aeronave remotamente tripulada é comum o piloto ter uma visão limitada, onde fica exposto aos perigos do ambiente como: galhos de arvores, postes, prédios e entre outros. Para solucionar esse problema é comum encontra em um sistema de <i>Detect&Avoid</i>
Sensor  → uControlador → Controladora de voo
<br>Definição dos componentes:
<br>→ gy-us42 - sensor ultrassonico com alcance de 0,2 á 7,2m e sua frequência de resposta é de 15Hz, e  sua folha de dados é possivel encontrar o feixe de alcance desse sensor.
<br>→ esp32 - microcontrolador 
<br>→ pixhawk - controladodora de voo com frimware ArduPilot instalado 

<br>Levando em conta que a velocidade maxima do drone é de 5m/s, e o tempo de resposta do sensor é de 600ms, para que o drone não sofra a colisão o objeto precisa ser visto a pelo menos  
