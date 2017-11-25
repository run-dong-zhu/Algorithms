from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener
import json
import time
import io



#consumer key, consumer secret, access token, access secret.
ckey="OSP2ioZWIAjz3p0OD01qknYTQ"
csecret="ucK8oSGHNy62ZyCP3IWgeum48tDhFIDLDMDdnICX13ClWDAeFk"
atoken="4771806373-bfZm8MRDlklf8pAWOTqanRPDEcSeB9TQu6BNWHS"
asecret="YXf3nXykh6Ed3B79P8PjHfF0I7zZRBLWDIMnXPI1DzHkG"

class listener(StreamListener):

    def on_data(self, data):        

        try:
            all_data = json.loads(data)
            tweet = (all_data["text"] + "\r\n").encode('utf-8')
            
            print(tweet)

            '''
            with open("xy.txt", "ab") as myfile:
                myfile.write(tweet)
            '''
            saveFile = open('demo.txt', 'ab')
            saveFile.write(tweet)
            saveFile.close()
        
            return True
        except BaseException as e:
            print(str(e))
            time.sleep(5)


    def on_error(self, status):
        print (status)

auth = OAuthHandler(ckey, csecret)
auth.set_access_token(atoken, asecret)

twitterStream = Stream(auth, listener())
twitterStream.filter(track=["blockchain"])
