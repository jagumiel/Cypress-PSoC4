# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Users\jagumiel\Documents\PSoC Creator\PSoC-101\PSoC-101\Lesson7.cydsn\Lesson7.cyprj
# Date: Mon, 06 Jul 2020 08:05:57 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]


# Component constraints for D:\Users\jagumiel\Documents\PSoC Creator\PSoC-101\PSoC-101\Lesson7.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Users\jagumiel\Documents\PSoC Creator\PSoC-101\PSoC-101\Lesson7.cydsn\Lesson7.cyprj
# Date: Mon, 06 Jul 2020 08:05:52 GMT
