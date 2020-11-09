# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jkoers <jkoers@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 15:36:08 by jkoers        #+#    #+#                  #
#    Updated: 2020/11/09 17:26:15 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= libftprintf

TESTNAME		= testor

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror

SRCEXT      	= c
SRCDIR      	= .
HEADERDIR		= .
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= bin
LIBS			= -I../libft/include/
HEADERS			= ft_printf.h

UNITTEST		= test/test_ft_numtobase.c

SOURCES     	= $(SRCDIR)/ft_printf.c \
				  $(SRCDIR)/handlers.c \
				  $(SRCDIR)/handlers2.c \
				  $(SRCDIR)/i_tostr.c \
				  $(SRCDIR)/exit_error.c
				
OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,\
				  $(SOURCES:$(SRCEXT)=$(OBJEXT)))
dis				= $(subst lib,,$(NAME))
STARTGREEN		= @echo "\033[38;2;0;255;0m\c"
RESETCOLOR		= @echo "\033[0m\c"

##

all: $(BINDIR)/$(NAME).a

$(NAME): $(BINDIR)/$(NAME).a

static: $(BINDIR)/$(NAME).a

$(BINDIR)/$(NAME).a: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	$(STARTGREEN)
	make -C../libft/ static
	$(RESETCOLOR)
	cp ../libft/bin/libft.a $(BINDIR)/$(NAME).a 
	ar -crs $(BINDIR)/$(NAME).a $(OBJECTS)
	
##

clean:
	/bin/rm -rf $(BUILDDIR)/
	$(STARTGREEN)
	make -C../libft/ clean
	$(RESETCOLOR)

fclean: clean
	/bin/rm -f $(TESTNAME)
	/bin/rm -rf $(BINDIR)/
	$(STARTGREEN)
	make -C../libft/ fclean
	$(RESETCOLOR)

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@ $(LIBS)

.PHONY: all so static clean fclean re libft
