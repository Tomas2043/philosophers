# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 15:11:33 by toandrad          #+#    #+#              #
#    Updated: 2026/02/23 11:59:17 by toandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BROWN='\033[0;33m'
GRAY='\033[2;37m'
YELLOW='\033[1;33m'
NC='\033[0m'

VERBOSE=0
if [ "$1" = "-v" ] || [ "$1" = "--verbose" ]; then
	VERBOSE=1
fi

run_test() {
	if [ $VERBOSE -eq 1 ]; then
		"$@"
	else
		"$@" > /dev/null 2>&1
	fi
}

echo "Philo testing..."

echo -e "${BROWN}===================== 1st batch (Should never die) =====================${NC}"
echo -n -e "${YELLOW}TEST 1${NC} - Basic Case - ${GRAY}(./philo 5 800 200 200)${NC}"
run_test timeout 5s ./philo 5 800 200 200
if [ $? -eq 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (timed out - no death)"
else
	echo -e "\n\t${RED}FAIL${NC} (philosopher died)"
fi

echo -n -e "${YELLOW}TEST 2${NC} - Tight timing - ${GRAY}(./philo 4 410 200 200)${NC}"
run_test timeout 5s ./philo 4 410 200 200
if [ $? -eq 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (timed out - no death)"
else
	echo -e "\n\t${RED}FAIL${NC} (philosopher died)"
fi

echo -n -e "${YELLOW}TEST 3${NC} - Lots of philosophers - ${GRAY}(./philo 100 800 200 200)${NC}"
run_test timeout 5s ./philo 100 800 200 200
if [ $? -eq 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (timed out - no death)"
else
	echo -e "\n\t${RED}FAIL${NC} (philosopher died)"
fi

echo -n -e "${YELLOW}TEST 4${NC} - 2 Philosophers - ${GRAY}(./philo 2 400 200 200)${NC}"
run_test timeout 5s ./philo 2 400 200 200
if [ $? -eq 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (timed out - no death)"
else
	echo -e "\n\t${RED}FAIL${NC} (philosopher died)"
fi

echo -e "\n${BROWN}===================== 2nd batch (Should die) =====================${NC}"
echo -n -e "${YELLOW}TEST 1${NC} - Should die around 310ms - ${GRAY}(./philo 4 310 200 100)${NC}"
run_test timeout 5s ./philo 4 310 200 100
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (philosopher died)"
else
	echo -e "\n\t${RED}FAIL${NC} (timed out - no death)"
fi

echo -n -e "${YELLOW}TEST 2${NC} - 1 Philosopher (1 fork deadlock) - ${GRAY}(./philo 1 800 200 200)${NC}"
run_test timeout 5s ./philo 1 800 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (philosopher died - avoided deadlock)"
else
	echo -e "\n\t${RED}FAILS${NC} (timed out - no death)"
fi

echo -n -e "${YELLOW}TEST 3${NC} - Impossible timing - ${GRAY}(./philo 2 200 200 200)${NC}"
run_test timeout 5s ./philo 2 200 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (philosopher died)"
else
	echo -e "\n\t${RED}FAIL${NC} (timed out - no death)"
fi

echo -e "\n${BROWN}===================== 3rd batch (Specific meal count) =====================${NC}"
echo -n -e "${YELLOW}TEST 1${NC} - Each one eats 7 times - ${GRAY}(./philo 5 800 200 200 7)${NC}"
run_test timeout 10s ./philo 5 800 200 200 7
if [ $? -eq 0 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (program exits cleanly)"
else
	echo -e "\n\t${RED}FAIL${NC} (timed out - program didn't exit)"
fi

echo -n -e "${YELLOW}TEST 2${NC} - Each one eats 3 times - ${GRAY}(./philo 4 410 200 200 3)${NC}"
run_test timeout 10s ./philo 4 410 200 200 3
if [ $? -eq 0 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (program exits cleanly)"
else
	echo -e "\n\t${RED}FAIL${NC} (timed out - program didn't exit)"
fi

echo -n -e "${YELLOW}TEST 3${NC} - Each one eats once - ${GRAY}(./philo 5 800 200 200 1)${NC}"
run_test timeout 10s ./philo 5 800 200 200 1
if [ $? -eq 0 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (program exits cleanly)"
else
	echo -e "\n\t${RED}FAIL${NC} (timed out - program didn't exit)"
fi

echo -e "\n${BROWN}===================== 4th batch (Invalid inputs) =====================${NC}"
echo -n -e "${YELLOW}TEST 1${NC} - No arguments - ${GRAY}(./philo)${NC}"
run_test timeout 5s ./philo
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo -n -e "${YELLOW}TEST 2${NC} - Wrong amount of arguments - ${GRAY}(./philo 5 800)${NC}"
run_test timeout 5s ./philo 5 800
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo -n -e "${YELLOW}TEST 3${NC} - Negative number - ${GRAY}(./philo -5 800 200 200)${NC}"
run_test timeout 5s ./philo -5 800 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo -n -e "${YELLOW}TEST 4${NC} - Zero philosophers - ${GRAY}(./philo 0 800 200 200)${NC}"
run_test timeout 5s ./philo 0 800 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo -n -e "${YELLOW}TEST 5 ${NC} - Non-number argument - ${GRAY}(./philo abc 800 200 200)${NC}"
run_test timeout 5s ./philo abc 800 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo -n -e "${YELLOW}TEST 6${NC} - Mixed (number + letters) - ${GRAY}(./philo 5 80a 200 200)${NC}"
run_test timeout 5s ./philo 5 80a 200 200
if [ $? -ne 124 ]; then
	echo -e "\n\t${GREEN}PASS${NC} (prints error + exits)"
else
	echo -e "\n\t${RED}FAIL${NC} (not expected behavior)"
fi

echo ""
echo "Tests complete!"
