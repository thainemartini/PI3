/* PI - Código inicial
Comunicação do esp32 com o sonar através da comunicação I2C
Endereço do sonar 0x70
código para leitura 0xE1
*/

#include <stdio.h>
#include "driver/i2c.h"

#define I2C_ADDR	0x70//endereço do sensor
#define CMD_READ 0x1 // comando de leitura do sensor

static esp_err_t i2c_master_init(void) //iniciando os parametros da comunicação i2c
{
    int i2c_master_port = I2C_NUM_0;
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = GPIO_NUM_21,
        .scl_io_num = GPIO_NUM_22,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,//Frequência em Hz
    };

    i2c_param_config(i2c_master_port, &conf);

    return i2c_driver_install(i2c_master_port, conf.mode, 0, 0, 0);
}

void app_main() {
	i2c_master_init();
	uint8_t data[2];
	int dist;
	int a=7;//inserir a distancia em cm para o drone parar

    while (1) {

        //manda um sinal para o sensor
    	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, I2C_ADDR << 1 | I2C_MASTER_WRITE, true);
        i2c_master_write_byte(cmd, CMD_READ, true);
        i2c_master_stop(cmd);
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS);
        i2c_cmd_link_delete(cmd);
        vTaskDelay(70 / portTICK_RATE_MS); // espera pela leitura do sensor

        //recebe o valor do sensor
        cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, I2C_ADDR << 1 | I2C_MASTER_READ, true);
        i2c_master_read_byte(cmd, &data[0], I2C_MASTER_ACK);
        i2c_master_read_byte(cmd, &data[1], I2C_MASTER_NACK);
        i2c_master_stop(cmd);
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS);
        i2c_cmd_link_delete(cmd);

        dist = (data[0] << 8) | data[1]; // combina os dois bytes em um valor único
        printf("Distancia: %d cm\n", dist); // exibe a distância no terminal
        vTaskDelay(1000 / portTICK_RATE_MS); // aguarda 1 segundo para fazer nova leitura
        //
        if(dist<a && dist>0){
        	//em construção para parar o drone
        	vTaskDelay(3000 / portTICK_RATE_MS);
        }
        //
    }
}

