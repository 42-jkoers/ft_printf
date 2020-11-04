# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by joppe         #+#    #+#                  #
#    Updated: 2020/11/03 13:17:39 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Makefile for a generic project

NAME      	:= name

CC          := gcc
CFLAGS      :=

HEADERDIR	:= .
SRCDIR      := .
BUILDDIR    := obj
SRCEXT      := c
OBJEXT      := o
LIBS		:= -I../libft/include/ -L../libft/bin/ -lft

SOURCES     := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

$(NAME): all

all: $(BUILDDIR)/ $(OBJECTS)
	$(CC) $(CFLAGS) -I ${HEADERDIR}/ $(OBJECTS) -o $(NAME) ${LIBS}

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I ${HEADERDIR}/ -c $< -o $@ $(LIBS)

.PHONY: all clean fclean re directories
