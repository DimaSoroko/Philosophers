#-------------------------------------------------------------------ASCIIART---------------------------------------------------------------------------------------------

define HEADLOGO

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════ 
endef
export HEADLOGO

#-------------------------------------------------------------------COLORS---------------------------------------------------------------------------------------------

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

# --------------------------------------------------------------------VARS ---------------------------------------------------------------------------------------------

NAME			= philo		               												# name of the program

CC				= gcc -fsanitize=thread		                       						# compiler

FLAGS			= -Wall -Wextra -Werror   												# flags

RM				= rm -f           														# remove 
						
# -----------------------------------------------------------------SOURCE FILES ----------------------------------------------------------------------------------------

SRCS			= 	./srcs/ft_atoi.c\
					./srcs/init_data.c\
					./srcs/philo.c\
					./srcs/routine.c\
					./srcs/simulation.c\
					./srcs/time_managment.c\
					./srcs/utils.c
					

OBJS	   		 = $(SRCS:.c=.o)       	 												# trasnforms all the ".c" files into ".o" (objects)

HEADER			 = -Iincludes			 												# adds headers

NORM 			 = @norminette 														 	# checking the norm 


# -------------------------------------------------------------------- RULES -------------------------------------------------------------------------------------------

.c.o:		
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all:	    $(NAME)   																	# will execute NAME rule
		
$(NAME):	$(OBJS)
			$(NORM)
			@echo $(Green)√$(Color_Off)$(BBlue)Norm is OK!$(Color_Off);
			@echo $(BRed) "$$HEADLOGO" $(Color_Off)
			@$(CC) $(OBJS) -o $(NAME)
			@echo $(BGreen)√$(Color_Off)$(BBlue)Philosophers Has Been Compiled!$(Color_Off);
			@echo $(BBlue)To Use Philosophers :$(BGreen)./philo With 4 Arguments $(Color_Off);
			@echo $(BBlue)1:$(Color_Off)$(BGreen)Number of Philosophers [Not more then 200]$(Color_Off);
			@echo $(BBlue)2:$(Color_Off)$(BGreen)Time to Die [Not Less Then 60]$(Color_Off);
			@echo $(BBlue)3:$(Color_Off)$(BGreen)Time to Eat [Not Less Then 60]$(Color_Off);
			@echo $(BBlue)4:$(Color_Off)$(BGreen)Time to Sleep [Not Less Then 60]$(Color_Off);
			@echo $(BBlue)5 [OPTIONAL] :$(BGreen)Number of Times Each Philosopher Must Eat $(Color_Off);

clean: 																					# remove all .o
			@$(RM) $(OBJS) 
			@echo $(BGreen)√$(Color_Off)$(BBlue)Clean Succeeded, All The '.o' Has Been Removed!$(Color_Off);
														         
fclean: clean                            												# force remove NAME
			@$(RM) $(NAME) 
			@echo $(BGreen)√$(Color_Off)$(BBlue)Fclean Succeeded, Everything Has Been Removed!$(Color_Off);


re: fclean all 																			# rule to recompile MAKEFILE (will remove everything and allows to recompile again)
			@echo $(BGreen)√$(Color_Off)$(BBlue)Recompile Succeeded!$(Color_Off);	

leaks:		${NAME}																		# adds valgrind to check system leaks
			valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
			@echo $(BBlue)No Leaks Detected$(Color_Off);

# ----------------------------------------------------------------------PHONY --------------------------------------------------------------------------------------------

.PHONY: all clean fclean leaks re             											# in phony section we need to include all used rules