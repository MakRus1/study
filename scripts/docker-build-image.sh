set -o errexit

source ./scripts/set-env.sh

docker build -t ${DOCKER_IMAGE_NAME}  .
