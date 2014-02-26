#!/bin/bash

MYDIR=$(dirname $0)

. $MYDIR/common.sh

rsync -av --files-from=$FILESET $MQL4DIR/ $SRC_MQL4DIR/
