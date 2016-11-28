
ROOTDIR = $(CURDIR)/../../../..
SCRIPTDIR = $(ROOTDIR)/scripts/header_gen

SRC = adc_regs.src
SRC+= clkgen_regs.src
SRC+= ctimer_regs.src
SRC+= flashctrl_regs.src
SRC+= gpio_regs.src
SRC+= iomstr_regs.src
SRC+= ioslave_regs.src
SRC+= mcuctrl_regs.src
SRC+= mcuctrlpriv_regs.src
SRC+= rstgen_regs.src
SRC+= rtc_regs.src
SRC+= uart_regs.src
SRC+= vcomp_regs.src
SRC+= wdt_regs.src

ARMSRC = itm_regs.arm.src
ARMSRC+= nvic_regs.arm.src
ARMSRC+= sysctrl_regs.arm.src
ARMSRC+= systick_regs.arm.src
ARMSRC+= tpiu_regs.arm.src

HEADERS = $(SRC:%_regs.src=../am_reg_%.h)
HEADERS+= $(ARMSRC:%_regs.arm.src=../am_reg_%.h)

VPATH = ..

.PHONY: all clean realclean prep
all: $(ARMSRC) $(HEADERS)

$(ARMSRC):
	$(error ARM source files not found. Check git repo)
    
prep:
	./prep.sh

realclean:
	@rm -rf $(HEADERS)

$(HEADERS): prep

am_reg_%.h: source/%_regs.src
	python3 $(SCRIPTDIR)/header_gen.py $< > $@ ;\
	dos2unix $@

am_reg_%.h: source/%_regs.arm.src
	python3 $(SCRIPTDIR)/header_gen.py $< > $@ ;\
	dos2unix $@
