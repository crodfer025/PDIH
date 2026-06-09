#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tu Nombre");
MODULE_DESCRIPTION("Un driver LKM sencillo para Linux.");
MODULE_VERSION("0.1");

static char *name = "world";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in log");

// Función que se ejecuta al cargar el módulo
static int __init helloBBB_init(void) {
    // printk es el equivalente a printf pero para el kernel
    printk(KERN_INFO "EBB: Hello %s from the BBB LKM!\n", name);
    return 0;
}

// Función que se ejecuta al descargar el módulo
static void __exit helloBBB_exit(void) {
    printk(KERN_INFO "EBB: Goodbye %s from BBB LKM!\n", name);
}

// Registro de las funciones en el kernel
module_init(helloBBB_init);
module_exit(helloBBB_exit);
