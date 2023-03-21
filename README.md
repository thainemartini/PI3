# PI3
Repositorio designado a disciplina de projeto Integrador 3, o projeto em questão é um Detect and Avoid para um drone de peueno porte.
<br><b>Objetivo:</b> Um sistema que detecta e evita objetos, para uma aeronave remotamente tripulada.
<br><b>Introdução:</b> em uma aeronave remotamente tripulada é comum o piloto ter uma visão limitada, onde fica exposto aos perigos do ambiente como: galhos de arvores, postes, prédios e entre outros. Para solucionar esse problema é comum encontra em um sistema de <i>Detect&Avoid</i>
<br><img src="diagramadeblocos.png">
<br>
<br>Definição dos componentes:
<br>
<br>→ Esp32 - microcontrolador
<br>  Frequência do clock: 160MHz
<br>  Fácil acesso no Laboratório de Drones
<br>
<br>→ Pixhawk - controladora de voo 
<br>  Firmware: ArduPilot
<br>  Fácil acesso no Laboratório de Drones
<br>  Frequência de trabalho de 187MHz
<br>
<br>→ gy-us42 - sensor ultrassônico 
<br>  Alcance de 0,2 á 7,2m 
<br>  Resolução de 1mm
<br>  Frequência de resposta é de 15Hz, e sua folha de dados é possível encontrar o feixe de alcance desse sensor.
<br>
<br>Levando em conta que a velocidade maxima do drone é de 5m/s, e o tempo de resposta do sensor é de 600ms, para que o drone não sofra a colisão o objeto precisa ser visto a pelo menos  
<br>O cronograma a ser seguido, se encontra a seguir:
<br><img src="image.png">

