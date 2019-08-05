#include <glib.h>
#include <glib/gprintf.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <inttypes.h>

struct context {
	GError * error;
	GKeyFile * key_file;
};

struct context initContext(){
	struct context contxt;
	contxt.error = NULL;
	contxt.key_file = g_key_file_new ();
	return contxt;
}



char * getBatAtr(char* atr, struct context contxt);
char * getBatAtr(char * atr, struct context contxt){
        g_autofree gchar * val = g_key_file_get_string (contxt.key_file, "Battery", atr, &contxt.error);
	if (val == NULL &&
	    !g_error_matches (contxt.error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_KEY_NOT_FOUND))
	{
		g_warning ("Error finding key in key file: %s", contxt.error->message);
		errx(1, "asdasd");
	}
	else if (atr == NULL)
	{
		// Fall back to a default value.
		atr = g_strdup ("default-value");
	}
	//outP = realloc(val, strlen(val));
	//*outP = val;
	
	return val;
}


int main(){
	struct context contxt = initContext();
	
	if (!g_key_file_load_from_file (contxt.key_file, "batterymon.ini", G_KEY_FILE_NONE, &contxt.error))
	{
		if (!g_error_matches (contxt.error, G_FILE_ERROR, G_FILE_ERROR_NOENT))
			g_warning ("Error loading key file: %s", contxt.error->message);
		return 0;
	}
	char * lowP = NULL;
	char * path = NULL;
	lowP = getBatAtr("low", contxt);
	path = getBatAtr("path", contxt);
	int low = strtoimax(lowP, NULL, 10);

	/* if (lowP == NULL) { */
	/* 	errx(); */
	/* } */
	/* if (path == NULL) { */
	/* 	errx(); */
	/* } */

	printf ("low: %s\n", lowP);
	printf ("path: %s\n", path);

	//free(lowP);//TODO goto for freedom
	//free(path);
	//free context
	return 0;
}


