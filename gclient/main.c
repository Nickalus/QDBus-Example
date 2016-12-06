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
                                                 "VariantTest",
                                                 NULL,
                                                 G_VARIANT_TYPE("(v)"),
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

  //Get the variant from the tuple
  GVariant * myVariant = g_variant_get_variant(g_variant_get_child_value(reply, 0));
  
  //convert the variant to an int
  int myInt = 0;
  g_variant_get(myVariant, "i", &myInt);

  //Display the int 
  g_print("%i", myInt);
}
