#Twitter

# -*- coding: utf-8 -*-
import sys

import codecs
import tweepy

CONSUMER_KEY = 'L52oAYiKwgdgFJmzKotOQ'
CONSUMER_SECRET = '9PdP904OOsVitM8xICBta8cSujhwSW8YCjS1cdpg'


ACCESS_KEY = '2233387286-iT6hguBFYuVUrIII2ZVuuWfmUedsiNVymlA9yQ3'
ACCESS_SECRET = 'HAOy4hmFfARl1UBHgd3tNP5K7GMY763Aan7U9z28gSSCO'
 
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)

api = tweepy.API(auth)

user = api.get_user('roo396')
print user.screen_name
print user.followers_count
for friend in user.friends():
	print friend.screen_name

api.update_status("@roo396 creo que va a dormir bien hoy")

# result = api.user_timeline("josemlp91")
# print result

# for status in result:
#     print status.text