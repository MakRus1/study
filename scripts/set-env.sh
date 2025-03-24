set -o errexit

if [ ! -f './scripts/.env' ]; then
	return 1
fi

export $(grep -v '^#' ./scripts/.env | xargs)

export DOCKER_IMAGE_TAG="${VERSION}"
export DOCKER_IMAGE_NAME="${DOCKER_IMAGE}:${VERSION}"
