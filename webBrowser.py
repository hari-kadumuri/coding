# import webbrowser
# import time

# while True:
#     url = 'https://youtu.be/Qryz5rAm4FI?t=434'
#     chromedir = 'C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe'
#     webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chromedir))
#     webbrowser.get('chrome').open(url)
#     time.sleep(631)

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

browser = webdriver.Firefox()
url = 'https://google.co.in'
browser.get(url)
main_window = browser.current_window_handle

# chromedir = 'C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe'
# webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chromedir))
# webbrowser.get('chrome').open(url)

# opening new tab
webbrowser.find_element_by_tag_name('body').send_keys(Keys.CONTROL + 't')
webbrowser.get(url)

# waiting for the song to finish
time.sleep(5)

#closing tab
webbrowser.find_element_by_tag_name('body').send_keys(Keys.CONTROL + 'w')
