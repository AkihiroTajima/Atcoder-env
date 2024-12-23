# Ubuntuの公式コンテナを軸に環境構築
FROM ubuntu

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive
# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

# インフラを整備
RUN apt-get update && \
    apt-get install -y zsh time tzdata tree git curl

# デフォルトシェルをZ shellにする
RUN chsh -s /bin/zsh

# C++, Python3, PyPy3の3つの環境想定
RUN apt-get update && \
    apt-get install -y gcc-12 g++-12 python3 python3-pip pypy3

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# コンテスト補助アプリケーションをインストール
RUN pip install online-judge-tools --break-system-packages

# # AHC用のRustのinstall
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y
ENV PATH $PATH:/home/root/.cargo/bin

WORKDIR /root/problems
WORKDIR /root/library