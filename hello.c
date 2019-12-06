#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int
hello_modevent(module_t mod __unused, int event, void *arg __unused)
{
    int error = 0;
    switch (event) {
	    case MOD_LOAD:
		    uprintf("MOD_LOAD called from hello_modevent\n");
		    break;
	    case MOD_UNLOAD:
		    uprintf("MOD_UNLOAD called from hello_modevent\n");
		    break;
	    default:
		    error = EOPNOTSUPP;
		    break;
    }

    return error;
}

static moduledata_t hello_mod = {
    "hello",
    hello_modevent,
    NULL
};

DECLARE_MODULE(hello, hello_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
