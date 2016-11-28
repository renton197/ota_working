#! /bin/sh

echo 'Preparing reg src files...'

echo 'Moving files...'
cp upstream/*.src .
mv clk_gen_rtc_regs.src   rtc_regs.src
mv clk_gen_cg_regs.src    clkgen_regs.src

echo 'Fixing filenames...'
sed -i 's/CLK_GEN/CLKGEN/g' clkgen_regs.src
mv flash_ctrl_regs.src flashctrl_regs.src
sed -i 's/FLASH_CTRL/FLASHCTRL/g' flashctrl_regs.src
mv mcu_ctrl_regs.src   mcuctrl_regs.src
sed -i 's/MCU_CTRL/MCUCTRL/g' mcuctrl_regs.src

echo 'Miscellaneous other fixes...'
sed -i 's/The command fields are as follow://' iomstr_regs.src
sed -i 's/    name            =   IOMSTRINT/\0\n    friendly        =   INT/' iomstr_regs.src

echo 'Generating private MCUCTRL regs...'
cp mcuctrl_regs.src mcuctrlpriv_regs.src
sed -i 's/MCUCTRL/MCUCTRLPRIV/g' mcuctrlpriv_regs.src

echo 'Removing line break tags...'
sed -i 's/\(<br>\)\|\(<BR>\)//g' iomstr_regs.src ioslave_regs.src

echo 'Removing <pre> tags'
sed -i '/<pre>/,/<\/pre>/ d' iomstr_regs.src

echo 'Applying patch to ADC reg file'
patch < adc-changes.patch

echo 'INTERNAL-izing secret registers.'
sed -i 's/    name            =   BOOTLOADERLOW/\0\n    visible         =   0/' mcuctrl_regs.src
sed -i 's/    name            =   SHADOWVALID/\0\n    visible         =   0/' mcuctrl_regs.src
sed -i 's/    name            =   AIKEY/\0\n    visible         =   0/' mcuctrl_regs.src
sed -i 's/    name            =   XTALCTRL/\0\n    visible         =   0/' mcuctrl_regs.src

echo 'Reg src Conversion Complete'
