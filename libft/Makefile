# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by jkoers        #+#    #+#                  #
#    Updated: 2020/11/26 23:09:22 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= libft

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror

SRCEXT      	= c
SRCDIR      	= .
HEADERDIR		= .
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= .
HEADER			= libft.h

TESTNAME		= testor
UNITTEST		= test/test_ft_numtostr_pad.c

SOURCES =	ft_abs.c \
            ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_includes.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_isspace.c \
            ft_itoa.c \
            ft_lstadd_back.c \
            ft_lstadd_front.c \
            ft_lstclear.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstlast.c \
            ft_lstmap.c \
            ft_lstnew.c \
            ft_lstpush_back.c \
            ft_lstpush_front.c \
            ft_lstsize.c \
            ft_max.c \
            ft_max_u.c \
            ft_memccpy.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_numlen.c \
            ft_numlen_u.c \
            ft_numtobase.c \
            ft_numtobase_u.c \
            ft_numtohexstr_precision_u.c \
            ft_numtohexstr_u.c \
            ft_numtostr.c \
            ft_numtostr_precision.c \
            ft_numtostr_precision_u.c \
            ft_numtostr_u.c \
            ft_padend.c \
            ft_padstart.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_putstr.c \
            ft_putstr_fd.c \
            ft_spit.c \
            ft_strcat.c \
            ft_strchr.c \
            ft_strcmp.c \
            ft_strcpy.c \
            ft_strdup.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncat.c \
            ft_strncmp.c \
            ft_strncpy.c \
            ft_strndup.c \
            ft_strndup_unsafe.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strset.c \
            ft_strtolower.c \
            ft_strtonum.c \
            ft_strtonum_u.c \
            ft_strtoupper.c \
            ft_strtrim.c \
            ft_substr.c \
            ft_tolower.c \
            ft_toupper.c
OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
				  $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
INCLUDENAME		= $(subst lib,,$(NAME))

##

all: $(BINDIR)/$(NAME).a

$(NAME): $(BINDIR)/$(NAME).a

##

static: $(BINDIR)/$(NAME).a

$(BINDIR)/$(NAME).a: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	ar -cr $(BINDIR)/$(NAME).a $(BUILDDIR)/*.$(OBJEXT)

##

so: $(BINDIR)/$(NAME).so

$(BINDIR)/$(NAME).so: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	$(CC) -shared $(BUILDDIR)/*.$(OBJEXT) -o $(BINDIR)/$(NAME).so

##

$(TESTNAME): $(BINDIR)/$(NAME).a $(UNITTEST)
	$(CC) $(CFLAGS) $(UNITTEST) -I$(HEADERDIR)/ -L$(BINDIR)/ \
	-l$(INCLUDENAME) -o $(TESTNAME)

##

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(TESTNAME)
	/bin/rm -rf $(BINDIR)/

re: fclean all

$(BUILDDIR)/:
	@mkdir -p $(BUILDDIR)

$(BINDIR)/:
	@mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADERDIR)/ -c $< -o $@

.PHONY: all help so static clean fclean re
