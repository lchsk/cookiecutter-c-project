#include <stdlib.h>
#include <stdio.h>

{% if cookiecutter.add_glib == 'y' -%}
#include <glib.h>
{% endif -%}
{% if cookiecutter.add_curses == 'y' -%}
#include <curses.h>
{% endif %}
int main(int argc, char** argv)
{
    printf("Hello world\n");

    return 0;
}
