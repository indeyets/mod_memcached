#include "base.h"
#include "plugin.h"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

typedef struct {
	PLUGIN_DATA;
	/* no config */
} plugin_data;

INIT_FUNC(mod_memcached_init)
{
	plugin_data *p;
	UNUSED(srv);
	p = calloc(1, sizeof(*p));
	return p;
}

FREE_FUNC(mod_memcached_free)
{
	plugin_data *p = p_d;
	UNUSED(srv);

	if (p)
		free(p);

	return HANDLER_GO_ON;
}

int mod_memcached_plugin_init(plugin *p)
{
	p->version = LIGHTTPD_VERSION_ID;
	p->name = buffer_init_string("memcached");
	p->init = mod_memcached_init;
	p->cleanup = mod_memcached_free;
	p->data = NULL;
	return 0;
}
