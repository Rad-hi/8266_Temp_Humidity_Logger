from Adafruit_IO import Client
import json

USER = "Radhi"
HUMIDITY_FEED = "humidity"
TEMPERATURE_FEED = "temperature"
KEY  = "aio_MpIL05TcdC32MHQ5kkZ2MkgiySxO"

humidity_vals = {}
temperature_vals = {}

def fetch_data(user, feed, key):
	adafruit_client = Client(user, key)
	all_data = adafruit_client.data(feed)

	for i in range(len(all_data)):
		if feed == HUMIDITY_FEED:
			humidity_vals[i] = json.loads(all_data[i].value)
		elif feed == TEMPERATURE_FEED:
			temperature_vals[i] = json.loads(all_data[i].value)

fetch_data(USER, HUMIDITY_FEED, KEY)
fetch_data(USER, TEMPERATURE_FEED, KEY)

print("---   HUMIDITY  ---\n\n", humidity_vals)
print("\n--- TEMPERATURE ---\n\n", temperature_vals)
