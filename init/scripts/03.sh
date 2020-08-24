#!/bin/zsh

app_id="19336fb3"
app_key="fa5fd9d7d176284cd549d3ef56a6f5f0"
base_url="https://od-api.oxforddictionaries.com/api/v2"
language_code="en-us"
end_point="entries"

if [ $# -eq 0 ]
then
    echo -n "Word to search: "
    read word_id
else
    word_id=$1
fi

url="$base_url/$end_point/$language_code/$word_id"

curl $url --header "app_id: ${app_id}" --header "app_key: ${app_key}" -i -o output -stderr log >> log 2>&1

if grep 'command not found' log > /dev/null
then
	echo "Command 'curl' not found"
	rm log
	exit 1
elif [ ! -e output ]
then
	echo "Check your Internet connection"
	rm log
	exit 1
fi

response_status=$(head -n 1 output | cut -d ' ' -f 2)
#echo $response_status

if [ $response_status -eq '404' ]
then
    echo "Word not found."
	rm output log
	exit 1
elif [ ! $response_status -eq '200' ]
then
	echo "Error: $response_status"
	rm output log
	exit 1
fi

echo "\nDefinitions:\n"
grep 'definitions' -A 1 output | grep -v 'definitions' | cut -d "\"" -f 2

if grep 'etymologies' -A 1 output > /dev/null
then
	echo "\nEtymologies:\n"
	grep 'etymologies' -A 1 output | grep -v 'etymologies' | cut -d "\"" -f 2
fi

echo ""

rm output log