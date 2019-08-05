#include <glib.h>
#include <glib/gprintf.h>
#include <stdio.h>


int main(){
	g_autoptr(GError) error = NULL;
	g_autoptr(GKeyFile) key_file = g_key_file_new ();

	if (!g_key_file_load_from_file (key_file, "key-file.ini", G_KEY_FILE_NONE, &error))
	{
		if (!g_error_matches (error, G_FILE_ERROR, G_FILE_ERROR_NOENT))
			g_warning ("Error loading key file: %s", error->message);
		return 0;
	}

	g_autofree gchar *val = g_key_file_get_string (key_file, "Group Name", "SomeKey", &error);
	if (val == NULL &&
	    !g_error_matches (error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_KEY_NOT_FOUND))
	{
		g_warning ("Error finding key in key file: %s", error->message);
		return 0;
	}
	else if (val == NULL)
	{
		// Fall back to a default value.
		val = g_strdup ("default-value");
	}

	printf ("outval: %s\n", val);
	return 0;
  
}



