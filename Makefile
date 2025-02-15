# nazwa glowna + co wywoluje
NAME = server client bonus
BONUS_NAME = server_bonus client_bonus

# opche kompilowanie + komenda na kasowanie
CFLAGS = -Wall -Wextra -Werror -I$(PRINTF_PATH)
CC = cc
RM = rm -f

# folder w ktorym znajduje sie printf i sciezka do pliku biblioteki
PRINTF_PATH = ft_printf
LIBFTPRINTF = $(PRINTF_PATH)/libftprintf.a

# Nazwa pliku z formatem + zamiana na object file
CLIENT_FILES = client.c
SERVER_FILES = server.c
CLIENT_OBJ = $(CLIENT_FILES:.c=.o)
SERVER_OBJ = $(SERVER_FILES:.c=.o)

# Pliki bonusowe
CLIENT_BONUS_FILES = client_bonus.c
SERVER_BONUS_FILES = server_bonus.c
BONUS_CLIENT_OBJ = $(CLIENT_BONUS_FILES:.c=.o)
BONUS_SERVER_OBJ = $(SERVER_BONUS_FILES:.c=.o)

#kompilacja wszystkiego
all: $(NAME)

#kompilacja serwera
server: $(SERVER_OBJ) $(LIBFTPRINTF)
	$(CC) $(SERVER_OBJ) -L$(PRINTF_PATH) -lftprintf -o server

#kompilacja klienta
client: $(CLIENT_OBJ) $(LIBFTPRINTF)
	$(CC) $(CLIENT_OBJ) -L$(PRINTF_PATH) -lftprintf -o client

#kompilacja calego bonusu
bonus: $(BONUS_NAME)

#kompilacja samego servera w bonusie
server_bonus: $(BONUS_SERVER_OBJ) $(LIBFTPRINTF)
	$(CC) $(BONUS_SERVER_OBJ) -L$(PRINTF_PATH) -lftprintf -o server_bonus

#kompilacja samego klienta w bonusie
client_bonus: $(BONUS_CLIENT_OBJ) $(LIBFTPRINTF)
	$(CC) $(BONUS_CLIENT_OBJ) -L$(PRINTF_PATH) -lftprintf -o client_bonus

#stworzenie biblioteki
$(LIBFTPRINTF):
	@make -C $(PRINTF_PATH)

#tzw. regula wzorcowa tworzy z pliku c plik obiektowy o takiej samej nazwie jak glowny plik
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#usuwa pliki obiektowe, rowniez w folderze gdzie znajduje sie biblioetka od printf
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_CLIENT_OBJ) $(BONUS_SERVER_OBJ)
	@make clean -C $(PRINTF_PATH)

#to samo co clean, ale dodatkowo czysci pliki wykonywalne
fclean: clean
	$(RM) server client server_bonus client_bonus
	@make fclean -C $(PRINTF_PATH)

#rebuild, czyli przebudowa wszystkiego na nowo (w skrocie usunie i stworzy na nowo)
re: fclean all

#Phony sprawia ze Make nie odbiera nazw za pliki, tylko za polecenia
.PHONY: all clean fclean re bonus
