
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

`default_nettype none

module MQTTPROJECT(

	//////////// CLOCK //////////
	input 		          		ADC_CLK_10,
	input 		          		MAX10_CLK1_50,
	input 		          		MAX10_CLK2_50,


	//////////// SW //////////
	input 		     [9:0]		SW,


	//////////// Accelerometer //////////
	output		          		GSENSOR_CS_N,
	input 		     [2:1]		GSENSOR_INT,
	output		          		GSENSOR_SCLK,
	inout 		          		GSENSOR_SDI,
	inout 		          		GSENSOR_SDO,

	//////////// Arduino //////////
	inout 		    [15:0]		ARDUINO_IO,
	inout 		          		ARDUINO_RESET_N

	);




//=======================================================
//  REG/WIRE declarations
//=======================================================


//=======================================================
//  Structural coding
//=======================================================





///////////////////////////////////////




accelerometerEOY u0 (
		.clk_clk                                   (MAX10_CLK1_50), 			//                              clk.clk
		.reset_reset_n                             (1'b1), 						//                            reset.reset_n
		.accelerometer_spi_0_external_interface_I2C_SDAT (GSENSOR_SDI),
		.accelerometer_spi_0_external_interface_I2C_SCLK (GSENSOR_SCLK),      
		.accelerometer_spi_0_external_interface_G_SENSOR_CS_N (GSENSOR_CS_N), 
		.accelerometer_spi_0_external_interface_G_SENSOR_INT (GSENSOR_INT),  
		.sw_external_connection_export             (SW),             			//           sw_external_connection.export
      .uart_0_external_connection_txd                       (ARDUINO_IO[0]),
		.uart_0_external_connection_rxd (ARDUINO_IO[1])
	);

	

endmodule
