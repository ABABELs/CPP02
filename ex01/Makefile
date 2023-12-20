# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babels <babels@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:28:50 by babels            #+#    #+#              #
#    Updated: 2023/12/20 13:40:14 by babels           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
SOURCES = main.cpp Fixed.Class.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.c++
	$(CXX) -c $(XXCFLAGS) -g3 $< -o $@ -I

${NAME}: ${OBJECTS}
	$(CXX) $(CXXFLAGS) -g3 -o ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}
	
fclean: clean
	rm -f ${NAME}

re: fclean all