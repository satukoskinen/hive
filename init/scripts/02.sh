#Delete an ACTIVE user
echo "Give the name of the user to be deleted:"
read username
if who | cut -d ' ' -f 1 | grep -x -e $username > /dev/null
then
    if sudo killall -u $username && sudo deluser --quiet --remove-all-files $username 2> /dev/null
    then
	echo "User $username successfully deleted."
    else
	echo "Error $?"
    fi
else
    echo "No active user with name $username found."
fi
