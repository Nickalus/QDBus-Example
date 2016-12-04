#include <gio/gio.h>

#include "common.h"

int main()
{
  GError *err = NULL;
  
  GDBusConnection * connection = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &err);
  
  if (err != NULL)
  {
    // Report error to user, and free error;
    g_print("%s\n", err->message);
    g_error_free(err);
  }
  
  GVariant * reply = g_dbus_connection_call_sync(connection,
                                                 SERVICE_NAME,
                                                 OBJECT_PATH,
                                                 INTERFACE,
                                                 "Run",
                                                 NULL,
                                                 G_VARIANT_TYPE("(i)"),
                                                 G_DBUS_CALL_FLAGS_NONE,
                                                 G_MAXINT,
                                                 NULL,
                                                 &err);
                                                 
  if (err != NULL)
  {
    // Report error to user, and free error;
    g_print("%s\n", err->message);
    g_error_free(err);
  }

  //Convert the varient into a 32bit integer
  g_print("%d", g_variant_get_int32(g_variant_get_child_value(reply, 0)));
}
