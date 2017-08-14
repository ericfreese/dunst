#include "draw.h"

#include <cairo.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <glib-object.h>
#include <locale.h>
#include <math.h>
#include <pango/pangocairo.h>
#include <pango/pango-attributes.h>
#include <pango/pango-font.h>
#include <pango/pango-layout.h>
#include <pango/pango-types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "src/dunst.h"
#include "src/markup.h"
#include "src/notification.h"
#include "src/settings.h"
#include "src/utils.h"

cairo_surface_t *cairo_surface;
cairo_t *cairo_context;
PangoFontDescription *pango_fdesc;

struct geometry geometry;

void draw_setup()
{
        x_parse_geometry(&geometry);
        x_setup();
        cairo_surface = x_cairo_create_surface();
        cairo_context = cairo_create(cairo_surface);
        pango_fdesc = pango_font_description_from_string(settings.font);
}

/* vim: set tabstop=8 shiftwidth=8 expandtab textwidth=0: */
