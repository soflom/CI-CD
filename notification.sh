#!/bin/bash

TELEGRAM_BOT_TOKEN="5890841465:AAEDUUPSaXPeYVe4kYEgX8xgPEmlH1Magjg"
TELEGRAM_USER_ID="1061045428"

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
if [[ "$CI_JOB_STATUS" == "success" ]];
then
    TEXT="Author:+$CI_COMMIT_AUTHOR 🍀 %0A%0AJob name: $CI_JOB_NAME%0A%0AStatus:+$CI_JOB_STATUS ✅%0A%0AProject:+$CI_PROJECT_NAME"
else
    TEXT="Author:+$CI_COMMIT_AUTHOR 🍀 %0A%0AJob name: $CI_JOB_NAME%0A%0AStatus:+$CI_JOB_STATUS ❌%0A%0AProject:+$CI_PROJECT_NAME"
fi
curl -s -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
